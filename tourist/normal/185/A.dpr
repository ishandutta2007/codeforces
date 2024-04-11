{$R-,S-,Q-,I-,O+}
const md = round(1e9+7);
var
  a,b,c: array [0..9,0..9] of int64;
  n,step: int64;
  i,j: longint;
begin
  read(n);
  a[1,1]:=3; a[1,2]:=1;
  a[2,1]:=1; a[2,2]:=3;
  b[1,1]:=1; b[1,2]:=0;
  b[2,1]:=0; b[2,2]:=1;
  step:=int64(1) shl 62;
  while step > 0 do
  begin
    for i:=1 to 2 do
      for j:=1 to 2 do c[i,j]:=(b[i,1]*b[1,j]+b[i,2]*b[2,j]) mod md;
    b:=c;
    if step and n <> 0 then
    begin
      for i:=1 to 2 do
        for j:=1 to 2 do c[i,j]:=(b[i,1]*a[1,j]+b[i,2]*a[2,j]) mod md;
      b:=c;
    end;
    step:=step shr 1;
  end;
  writeln(b[1,1]);
end.