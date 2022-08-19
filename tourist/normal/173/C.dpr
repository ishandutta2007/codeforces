{$R-,S-,Q-,I-,O+}
var
  sz,n,m,i,j,ans: longint;
  x,y,a,b,c,nb: array [0..510,0..510] of longint;
begin
  read(n,m);
  for i:=1 to n do
    for j:=1 to m do read(a[i,j]);
  ans:=-maxlongint;
  for i:=1 to n-2 do
    for j:=1 to m-2 do
    begin
      b[i,j]:=a[i,j]+a[i,j+1]+a[i,j+2]+a[i+1,j+2]+a[i+2,j+2]+a[i+2,j+1]+a[i+2,j];
      if b[i,j] > ans then ans:=b[i,j];
      c[i+2,j+2]:=a[i,j]+a[i,j+1]+a[i,j+2]+a[i+1,j]+a[i+2,j+2]+a[i+2,j+1]+a[i+2,j];
    end;
  for i:=1 to n do
  begin
    x[i,0]:=0;
    for j:=1 to m do x[i,j]:=x[i,j-1]+a[i,j];
  end;
  for j:=1 to m do
  begin
    y[0,j]:=0;
    for i:=1 to n do y[i,j]:=y[i-1,j]+a[i,j];
  end;
  for sz:=5 to n do
  begin
    if sz > m then break;
    if sz and 1 = 0 then continue;
    for i:=1 to n-sz+1 do
      for j:=1 to m-sz+1 do
      begin
        nb[i,j]:=c[i+sz-1,j+sz-3]+(x[i,j+sz-1]-x[i,j-1])+(y[i+sz-1,j+sz-1]-y[i,j+sz-1])+a[i+sz-1,j+sz-2];
        if nb[i,j] > ans then ans:=nb[i,j];
      end;
    for i:=sz to n do
      for j:=sz to m do
        c[i,j]:=b[i-sz+1,j-sz+3]+(x[i,j]-x[i,j-sz+1])+(y[i,j-sz+1]-y[i-sz,j-sz+1])+a[i-sz+1,j-sz+2];
    for i:=1 to n-sz+1 do
      for j:=1 to m-sz+1 do b[i,j]:=nb[i,j];
  end;
  writeln(ans);
end.