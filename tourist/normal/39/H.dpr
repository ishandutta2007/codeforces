{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  q,k,i,j,z,d: longint;
  a: array [0..1010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(k);
  for i:=1 to k-1 do
  begin
    for j:=1 to k-1 do
    begin
      z:=i*j; d:=0;
      while z > 0 do
      begin
        inc(d);
        a[d]:=z mod k;
        z:=z div k;
      end;
      for q:=d downto 1 do write(a[q]);
      if j < k-1 then write(' ');
    end;
    writeln;
  end;
  close(input);
  close(output);
end.