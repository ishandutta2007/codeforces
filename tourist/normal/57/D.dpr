{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,m,i,j,cnt,sx: longint;
  ans: int64;
  a: array [0..1010,0..1010] of char;
  row,col: array [0..1010] of longint;
  ch: char;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  for i:=1 to n do
    for j:=1 to m do
    begin
      read(ch);
      while not (ch in ['.','X']) do read(ch);
      a[i,j]:=ch;
    end;
  fillchar(row,sizeof(row),0);
  fillchar(col,sizeof(col),0);
  for i:=1 to n do
    for j:=1 to m do
      if a[i,j] = 'X' then
      begin
        row[i]:=j;
        col[j]:=i;
      end;
  ans:=0;
  cnt:=0; sx:=0;
  for i:=1 to n do
    for j:=1 to m do
      if a[i,j] = '.' then
      begin
        ans:=ans+i*cnt-sx;
        inc(cnt);
        inc(sx,i);
      end;
  cnt:=0; sx:=0;
  for j:=1 to m do
    for i:=1 to n do
      if a[i,j] = '.' then
      begin
        ans:=ans+j*cnt-sx;
        inc(cnt);
        inc(sx,j);
      end;
  for i:=1 to n do
    if row[i] <> 0 then
    begin
      ans:=ans+2*(row[i]-1)*(m-row[i]);
      for j:=i+1 to n do
        if (row[j] = 0) or (row[j] < row[j-1]) then break
        else ans:=ans+2*(row[i]-1)*(m-row[j]);
      for j:=i+1 to n do
        if (row[j] = 0) or (row[j] > row[j-1]) then break
        else ans:=ans+2*(row[j]-1)*(m-row[i]);
    end;
  for i:=1 to m do
    if col[i] <> 0 then
    begin
      ans:=ans+2*(col[i]-1)*(n-col[i]);
      for j:=i+1 to m do
        if (col[j] = 0) or (col[j] < col[j-1]) then break
        else ans:=ans+2*(col[i]-1)*(n-col[j]);
      for j:=i+1 to m do
        if (col[j] = 0) or (col[j] > col[j-1]) then break
        else ans:=ans+2*(col[j]-1)*(n-col[i]);
    end;
  writeln(ans*2/cnt/cnt:0:17);
  close(input);
  close(output);
end.