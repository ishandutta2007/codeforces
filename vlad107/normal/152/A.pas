var
  n,m,i,j,ans:longint;
  max:array[0..111]of char;
  a:array[0..111,0..111]of char;

begin
  readln(n,m);
  for i:=1 to m do max[i]:='0';
  for i:=1 to n do begin
    for j:=1 to m do begin
      read(a[i][j]);
      if (a[i][j]>max[j])then max[j]:=a[i][j];
    end;
    readln;
  end;
  ans:=0;
  for i:=1 to n do 
    for j:=1 to m do 
      if (a[i][j]=max[j])then begin
        inc(ans);
        break;
      end;
  writeln(ans);
end.