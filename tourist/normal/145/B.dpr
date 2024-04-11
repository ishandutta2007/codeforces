{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  a1,a2,a3,a4,i,j,c1,c2,len: longint;
  a,b: array [0..2000010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(a1,a2,a3,a4);
  len:=a1+a2;
  if (abs(a3-a4) > 1) or (1+a3+a4 > len) then writeln(-1) else
  begin
    if (a3 > a4) or (a3 = a4) and (a1 > a3) then
    begin
      for i:=1 to a3+a4+1 do
        if i and 1 = 1 then a[i]:=4
        else a[i]:=7;
    end else
      for i:=1 to a3+a4+1 do
        if i and 1 = 1 then a[i]:=7
        else a[i]:=4;
    c1:=0; c2:=0;
    for i:=1 to a3+a4+1 do
      if a[i] = 4 then inc(c1)
      else inc(c2);
    if (c1 > a1) or (c2 > a2) then writeln(-1) else
    begin
      for i:=1 to a3+a4+1 do b[i]:=1;
      for i:=1 to a3+a4+1 do
        if a[i] = 4 then
        begin
          b[i]:=b[i]+a1-c1;
          break;
        end;
      for i:=a3+a4+1 downto 1 do
        if a[i] = 7 then
        begin
          b[i]:=b[i]+a2-c2;
          break;
        end;
      for i:=1 to a3+a4+1 do
        for j:=1 to b[i] do write(a[i]);
      writeln;
    end;
  end;
//  close(input);
//  close(output);
end.