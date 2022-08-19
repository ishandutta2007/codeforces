{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,k,i: longint;
  s: ansistring;
  a: array [0..200010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n,k);
  readln(s);
  for i:=1 to n do a[i]:=Ord(s[i])-48;
  for i:=1 to n-1 do
    if (k > 0) and (a[i] = 4) and (a[i+1] = 7) then
    begin
      if i and 1 = 1 then a[i+1]:=4
      else a[i]:=7;
      dec(k);
      if i and 1 = 1 then
      begin
        if (i+2 <= n) and (a[i+2] = 7) then
        begin
          if k and 1 = 1 then a[i+1]:=7;
          break;
        end;
      end else
        if (i-1 >= 1) and (a[i-1] = 4) then
        begin
          if k and 1 = 1 then a[i]:=4;
          break;
        end;
    end;
  for i:=1 to n do write(a[i]);
  writeln;
  close(input);
  close(output);
end.