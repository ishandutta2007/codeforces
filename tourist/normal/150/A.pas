{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  d: array [0..100010] of int64;
  v: array [0..100010] of longint;
  n: int64;
  i,kd: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  kd:=0;
  for i:=2 to 10000000 do
    if int64(i)*i > n then break else
    if n mod i = 0 then
    begin
      inc(kd);
      d[kd]:=i;
      v[kd]:=0;
      while n mod i = 0 do
      begin
        inc(v[kd]);
        n:=n div i;
      end;
    end;
  if n > 1 then
  begin
    inc(kd);
    d[kd]:=n;
    v[kd]:=1;
  end;
  if kd = 0 then
  begin
    writeln(1);
    writeln(0);
  end else
  if kd = 1 then
  begin
    if v[1] = 1 then
    begin
      writeln(1);
      writeln(0);
    end else
    if v[1] = 2 then writeln(2) else
    begin
      writeln(1);
      writeln(d[1]*d[1]);
    end;
  end else
  if (kd = 2) and (v[1] = 1) and (v[2] = 1) then writeln(2) else
  begin
    writeln(1);
    writeln(d[1]*d[2]);
  end;
//  close(input);
//  close(output);
end.