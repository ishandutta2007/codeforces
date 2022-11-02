var
  ch,c1,c2:char;
  res,n,k,i,j:longint;
  f:array[0..111,0..111,'a'..'z']of longint;
  s:string;
  kq:array['a'..'z','a'..'z']of longint;

begin
  read(ch);
  s:='';
  while (ch<>' ')do begin
    s:=s+ch;
    read(ch);
  end;
  readln(k);
  readln(n);
  for c1:='a' to 'z' do 
    for c2:='a' to 'z' do 
      kq[c1][c2]:=0;
  for i:=1 to length(s)do
    for j:=0 to k do 
      for c1:='a' to 'z' do f[i][j][c1]:=-maxlongint;
  for i:=1 to n do begin
    read(c1,c2,c2);
    readln(kq[c1][c2]);
  end;
  for c1:='a' to 'z' do f[1][ord(c1<>s[1])][c1]:=0;
  res:=-maxlongint;
  for i:=1 to length(s)-1 do
    for j:=0 to k do 
      for c1:='a' to 'z' do 
        if (f[i][j][c1]>-maxlongint)then 
          for c2:='a' to 'z' do 
            if (f[i][j][c1]+kq[c1][c2]>f[i+1][j+ord(c2<>s[i+1])][c2])
              then f[i+1][j+ord(c2<>s[i+1])][c2]:=f[i][j][c1]+kq[c1][c2];
  for j:=0 to k do 
    for c1:='a' to 'z' do
      if (f[length(s)][j][c1]>res)then res:=f[length(s)][j][c1];
  writeln(res);
end.