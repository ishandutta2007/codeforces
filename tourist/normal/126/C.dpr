{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  n,i,j,ans: longint;
  a: array [0..2010,0..2010] of longint;
  ch: char;
  row,col: array [0..2010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    for j:=1 to n do
    begin
      read(ch);
      a[i,j]:=Ord(ch)-48;
    end;
    readln;
  end;
  fillchar(row,sizeof(row),0);
  fillchar(col,sizeof(col),0);
  ans:=0;
  for i:=1 to n do
    for j:=n downto i+1 do
    begin
      a[i,j]:=a[i,j] xor row[i] xor col[j];
      if a[i,j] = 1 then
      begin
        inc(ans);
        a[i,j]:=0;
        row[i]:=row[i] xor 1;
        col[j]:=col[j] xor 1;
      end;
    end;
  for i:=1 to n do a[i,i]:=a[i,i] xor row[i] xor col[i];
  fillchar(row,sizeof(row),0);
  fillchar(col,sizeof(col),0);
  for i:=n downto 1 do
    for j:=1 to i-1 do
    begin
      a[i,j]:=a[i,j] xor row[i] xor col[j];
      if a[i,j] = 1 then
      begin
        inc(ans);
        a[i,j]:=0;
        row[i]:=row[i] xor 1;
        col[j]:=col[j] xor 1;
      end;
    end;
  for i:=1 to n do inc(ans,a[i,i] xor row[i] xor col[i]);
  writeln(ans);
  close(input);
  close(output);
end.