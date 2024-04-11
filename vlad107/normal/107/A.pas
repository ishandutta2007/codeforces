
var
  z,t,kr,n,m,i,x,y:longint;
  r1,r2,r3,d,p,deg:array[0..500500]of longint;

begin
  read(n,m);
  fillchar(d,sizeof(d),$FF);
  for i:=1 to m do begin
    read(x,y,z);
    d[x]:=y;
    p[x]:=z;
    inc(deg[y]);
  end;
  for i:=1 to n do 
    if (deg[i]=0)and(d[i]>0)then begin
      inc(kr);
      r1[kr]:=i;
      x:=i;
      t:=1000000000;
      while (d[x]>0)do begin
        if (p[x]<t)then t:=p[x];
        x:=d[x]; 
      end;
      r2[kr]:=x;
      r3[kr]:=t;
    end;
  writeln(kr);
  for i:=1 to kr do writeln(r1[i],' ',r2[i],' ',r3[i]);
end.