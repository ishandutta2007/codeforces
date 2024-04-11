var
  n,m,i,j:longint;
  fx,fy:array[0..111,'a'..'z']of longint;
  res,s:ansistring;
  a:array[0..111,0..111]of char;

begin
  fillchar(fx,sizeof(fx),$0);
  fillchar(fy,sizeof(fy),$0);
  readln(n,m);
  for i:=1 to n do begin
    readln(s);
    for j:=1 to m do begin
      inc(fx[i][s[j]]);
      inc(fy[j][s[j]]);
    end;
    for j:=1 to m do a[i][j]:=s[j];
  end;
  res:='';
  for i:=1 to n do 
    for j:=1 to m do 
      if (fx[i][a[i,j]]=1)and(fy[j][a[i,j]]=1)then res:=res+a[i][j];
  writeln(res);
end.