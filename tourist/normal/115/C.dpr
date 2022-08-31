{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const md = 1000003;
var
  n,m,i,j,c,ans: longint;
  a: array [0..1000010] of char;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[(i-1)*m+j]);
    readln;
  end;
  ans:=1;
  for i:=1 to n do
  begin
    c:=3;
    for j:=1 to m do
    begin
      if (a[(i-1)*m+j] = '1') or (a[(i-1)*m+j] = '2') then c:=c and (1+j and 1);
      if (a[(i-1)*m+j] = '3') or (a[(i-1)*m+j] = '4') then c:=c and (2-j and 1);
    end;
    if c = 0 then ans:=0 else
    if c = 3 then ans:=ans*2 mod md;
  end;
  for j:=1 to m do
  begin
    c:=3;
    for i:=1 to n do
    begin
      if (a[(i-1)*m+j] = '1') or (a[(i-1)*m+j] = '4') then c:=c and (1+i and 1);
      if (a[(i-1)*m+j] = '2') or (a[(i-1)*m+j] = '3') then c:=c and (2-i and 1);
    end;
    if c = 0 then ans:=0 else
    if c = 3 then ans:=ans*2 mod md;
  end;
  writeln(ans);
  close(input);
  close(output);
end.