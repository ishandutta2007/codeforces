{$r-,q-,s-,i-,o+}
var
  st,x1,y1,x2,y2,tx,ty,tz:array[0..1111]of longint;
  n,m,i,j,q,res,kt,kst,px0,py0,px1,py1:longint;

  function right(x1,y1,x2,y2,x3,y3:longint):boolean;
    begin
      right:=(int64(x2-x1)*(y3-y1)-int64(y2-y1)*(x3-x1)) < 0;
    end;

  procedure qs(l,r:longint);
    var
      nom,i,j,tmp,xx,yy:longint;

    begin
      i:=l;j:=r;
      nom:=l+random(r-l+1);
      xx:=tx[nom];
      yy:=ty[nom];
      while (i<=j)do begin
        while (not right(px0,py0,xx,yy,tx[i],ty[i]))do inc(i);
        while (right(px0,py0,xx,yy,tx[j],ty[j]))do dec(j);
        if (i>j)then break;
        tmp:=tx[i];tx[i]:=tx[j];tx[j]:=tmp;
        tmp:=ty[i];ty[i]:=ty[j];ty[j]:=tmp;
        tmp:=tz[i];tz[i]:=tz[j];tz[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

begin
  randomize;
  read(n,m);
  for i:=1 to n do read(x1[i],y1[i]);
  for i:=1 to m do read(x2[i],y2[i]);
  res:=0;
  for i:=1 to n do begin
    kt:=0;
    for j:=1 to n do
      if (j<>i)and((y1[j]>y1[i])or((y1[j]=y1[i])and(x1[j]>=x1[i])))then begin
        inc(kt);
        tx[kt]:=x1[j];
        ty[kt]:=y1[j];
        tz[kt]:=1;
      end;
    if (kt<2)then continue;

    for j:=1 to m do
      if (y2[j]>y1[i])or((y2[j]=y1[i])and(x2[j]>=x1[i]))then begin
        inc(kt);
        tx[kt]:=x2[j];
        ty[kt]:=y2[j];
        tz[kt]:=0;
      end;
    px0:=x1[i];py0:=y1[i];
    qs(1,kt);

    for j:=1 to kt do
      if (tz[j]=1)then begin
        kst:=0;
        px1:=tx[j];py1:=ty[j];

        for q:=j+1 to kt do
          if (tz[q]=1)
            then inc(res,ord((kst=0)or(right(px1,py1,tx[st[kst]],ty[st[kst]],tx[q],ty[q]))))
            else begin
              while (kst>0)and(right(px1,py1,tx[st[kst]],ty[st[kst]],tx[q],ty[q]))do dec(kst);
              if (kst=0)then begin
                inc(kst);
                st[kst]:=q;
              end;
            end;
      end;
  end;
  writeln(res);
end.