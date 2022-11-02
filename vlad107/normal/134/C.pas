{$r-,q-,s-,i-,o+}
var
  x,tmp,tq,n,s,kh,kt,i:longint;
  h,q,ax,ay,a:array[0..500500]of longint;

  procedure down(x:longint);
    var
      tmp:longint;

    begin
      while (x>1)and(a[h[x]]>a[h[x shr 1]])do begin
        tmp:=h[x];h[x]:=h[x shr 1];h[x shr 1]:=tmp;
        x:=x shr 1;
      end;
    end;

  procedure up(x:longint);
    var
      tmp,y:longint;

    begin
      while (x+x<=kh)do begin
        y:=x+x;
        if (y<kh)and(a[h[y]]<a[h[y+1]])then inc(y);
        if (a[h[x]]>=a[h[y]])then break;
        tmp:=h[x];h[x]:=h[y];h[y]:=tmp;
        x:=y;
      end;
    end;

begin
{  assign(output,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);}
  read(n,s);
  for i:=1 to n do read(a[i]);

  kh:=0;kt:=0;
  for i:=1 to n do begin
    if (a[i]=0)then continue;
    inc(kh);
    h[kh]:=i;
    down(kh);
  end;

  while (kh>0)do begin
    x:=h[1];
    tmp:=h[1];h[1]:=h[kh];h[kh]:=tmp;
    dec(kh);
    up(1);

    if (kh<a[x])then begin
      writeln('No');
      exit;
    end;
    tq:=0;
    for i:=1 to a[x] do begin
      inc(kt);ax[kt]:=x;ay[kt]:=h[1];
      inc(tq);q[tq]:=h[1];

      dec(a[h[1]]);
      tmp:=h[1];h[1]:=h[kh];h[kh]:=tmp;
      dec(kh);
      up(1);
    end;
    for i:=1 to tq do
      if (a[q[i]]<>0)then begin
        inc(kh);
        h[kh]:=q[i];
        down(kh);
      end;
  end;
  writeln('Yes');
  writeln(kt);
  for i:=1 to kt do writeln(ax[i],' ',ay[i]);
  close(output);close(input);
end.