{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,j,tmp,r,min,x,ans: longint;
  ch: char;
  c: array [0..10] of longint;
  was: array [0..10010] of boolean;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  fillchar(was,sizeof(was),False);
  for i:=1 to n do
  begin
    for j:=1 to 4 do
    begin
      read(ch);
      while not (ch in ['1'..'6']) do read(ch);
      c[j]:=Ord(ch)-48;
    end;
    tmp:=c[3]; c[3]:=c[4]; c[4]:=tmp;
    for r:=1 to 4 do c[r+4]:=c[r];
    min:=1234567;
    for j:=1 to 4 do
    begin
      x:=0;
      for r:=j to j+3 do x:=x*10+c[r];
      if x < min then min:=x;
    end;
    was[min]:=True;
  end;
  ans:=0;
  for i:=0 to 9999 do
    if was[i] then inc(ans);
  writeln(ans);
  close(input);
  close(output);
end.