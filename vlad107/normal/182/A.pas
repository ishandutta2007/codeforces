const
  eps=1e-6;
  inf=1e15;

var
  dt,dl,cr,ax,ay,bx,by,min:extended;
  j,i,n,x:longint;
  d,x1,y1,x2,y2:array[0..500500]of extended;
  used:array[0..500500]of boolean;
  qd:array[0..1111,0..1111]of extended;

  function mind(a,b:extended):extended;
    begin
      if (a<b)then mind:=a else mind:=b;
    end;

  function dist(x1,y1,x2,y2:extended):extended;
    begin
      dist:=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    end;

  function distc(x1,y1,x2,y2,x3,y3,x4,y4:extended):extended;
    var
      cr,tmp:extended;
      
    begin
      cr:=dist(x1,y1,x3,y3);
      cr:=mind(cr,dist(x1,y1,x4,y4));
      cr:=mind(cr,dist(x2,y2,x3,y3));
      cr:=mind(cr,dist(x2,y2,x4,y4));
      if (abs(x3-x4)<eps)then begin
        if (y3>y4)then begin
          tmp:=y3;y3:=y4;y4:=tmp;
        end;
        if (y1-y3>-eps)and(y4-y1>-eps)then cr:=mind(cr,abs(x1-x3));
        if (y2-y3>-eps)and(y4-y2>-eps)then cr:=mind(cr,abs(x2-x3));
      end else begin
        if (x3>x4)then begin
          tmp:=x3;x3:=x4;x4:=tmp;
        end;
        if (x1-x3>-eps)and(x4-x1>-eps)then cr:=mind(cr,abs(y1-y3));
        if (x2-x3>-eps)and(x4-x2>-eps)then cr:=mind(cr,abs(y2-y3));        
      end;
      tmp:=x1;x1:=x3;x3:=tmp;
      tmp:=x2;x2:=x4;x4:=tmp;
      tmp:=y1;y1:=y3;y3:=tmp;
      tmp:=y2;y2:=y4;y4:=tmp;
      if (abs(x3-x4)<eps)then begin
        if (y3>y4)then begin
          tmp:=y3;y3:=y4;y4:=tmp;
        end;
        if (y1-y3>-eps)and(y4-y1>-eps)then cr:=mind(cr,abs(x1-x3));
        if (y2-y3>-eps)and(y4-y2>-eps)then cr:=mind(cr,abs(x2-x3));
      end else begin
        if (x3>x4)then begin
          tmp:=x3;x3:=x4;x4:=tmp;
        end;
        if (x1-x3>-eps)and(x4-x1>-eps)then cr:=mind(cr,abs(y1-y3));
        if (x2-x3>-eps)and(x4-x2>-eps)then cr:=mind(cr,abs(y2-y3));        
      end;
      if (cr-dl>eps)then cr:=inf;
      distc:=cr;
    end;

begin
  read(dl,dt);
  read(ax,ay,bx,by);
  read(n);
  for i:=1 to n do read(x1[i],y1[i],x2[i],y2[i]);
  inc(n);x1[n]:=ax;y1[n]:=ay;x2[n]:=ax;y2[n]:=ay;
  inc(n);x1[n]:=bx;y1[n]:=by;x2[n]:=bx;y2[n]:=by;
  for i:=1 to n do 
    for j:=1 to n do begin
       if (i<>j)
         then qd[i][j]:=distc(x1[i],y1[i],x2[i],y2[i],x1[j],y1[j],x2[j],y2[j])
         else qd[i][j]:=inf;
       if (j<>n)and(qd[i][j]<>inf)then qd[i][j]:=dl;
     end;
  for i:=1 to n do d[i]:=inf;      
  fillchar(used,sizeof(used),false);
  d[n-1]:=0;
  for i:=1 to n do begin
    min:=inf;
    x:=0;
    for j:=1 to n do 
      if (not used[j])and(d[j]<min)then begin
        min:=d[j];
        x:=j;
      end;
    if (x=0)then break;
    used[x]:=true;
    for j:=1 to n do 
      if (not used[j])
        then begin
          cr:=d[x]+qd[x][j];
          if (j<>n)then cr:=cr+dt;
          if (cr<d[j])then d[j]:=cr;
        end;
  end;
  if (abs(d[n]-inf)<eps)
    then writeln(-1)
    else writeln(d[n]:0:10);
end.