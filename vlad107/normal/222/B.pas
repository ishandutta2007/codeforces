var
  nx,ny:array[0..500500]of longint;
  a:array[0..1111,0..1111]of longint;
  tmp,k,n,m,i,j,x,y:longint;
  ch:char;

begin
  readln(n,m,k);
  for i:=1 to n do for j:=1 to m do read(a[i][j]);
  readln;
  for i:=1 to n do nx[i]:=i;
  for i:=1 to m do ny[i]:=i;
  for i:=1 to k do begin
    readln(ch,x,y);
    if (ch='r')then begin tmp:=nx[x];nx[x]:=nx[y];nx[y]:=tmp; end;
    if (ch='c')then begin tmp:=ny[x];ny[x]:=ny[y];ny[y]:=tmp; end;
    if (ch='g')then writeln(a[nx[x]][ny[y]]);
  end;
end.