{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
type matrix = array [0..3,0..3] of int64;
var
  n,i: longint;
  max,x,y,md,res: int64;
  a,b,c: matrix;
  q: array [0..1000010] of longint;

procedure power(var b:matrix;w:int64);
var
  i,j: longint;
  step: int64;
begin
  for i:=1 to 2 do
    for j:=1 to 2 do
    begin
      a[i,j]:=b[i,j];
      b[i,j]:=Ord(i = j);
    end;
  step:=int64(1) shl 62;
  while step > 0 do
  begin
    for i:=1 to 2 do
      for j:=1 to 2 do c[i,j]:=(b[i,1]*b[1,j]+b[i,2]*b[2,j]) mod md;
    b:=c;
    if step and w <> 0 then
    begin
      for i:=1 to 2 do
        for j:=1 to 2 do c[i,j]:=(b[i,1]*a[1,j]+b[i,2]*a[2,j]) mod md;
      b:=c;
    end;
    step:=step shr 1;
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,x,y,md);
  for i:=1 to n do read(q[i]);
  if n = 1 then
  begin
    writeln(q[1] mod md);
    halt;
  end;
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(c,sizeof(c),0);
  res:=0;
  for i:=1 to n do res:=res+q[i];
  res:=res mod md;
  b[1,1]:=0; b[1,2]:=1;
  b[2,1]:=1; b[2,2]:=1;
  power(b,x);
  max:=(q[n-1]*b[2,1]+q[n]*b[2,2]) mod md;
  b[1,1]:=3; b[1,2]:=0;
  b[2,1]:=1; b[2,2]:=1;
  power(b,x);
  res:=(res*b[1,1]-(q[1]+q[n])*b[2,1]) mod md;
  if res < 0 then res:=res+md;
  b[1,1]:=3; b[1,2]:=0;
  b[2,1]:=1; b[2,2]:=1;
  power(b,y);
  res:=(res*b[1,1]-(q[1]+max)*b[2,1]) mod md;
  if res < 0 then res:=res+md;
  writeln(res);
  close(input);
  close(output);
end.