{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const inf = round(1e9);
var
  z,f,a,b,md,i: longint;
  sl: string;
  can: array [0..10000010] of boolean;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(a,b,md);
  if a = inf then dec(a);
  if b = inf then dec(b);
  fillchar(can,sizeof(can),False);
  for i:=0 to b do
    if i = md then break else
    if i = 0 then can[0]:=True
    else can[md-i]:=True;
  f:=inf mod md;
  z:=0;
  for i:=0 to a do
  begin
    if i = md then break else
    if not can[z] then
    begin
      write('1 ');
      str(i,sl);
      while length(sl) < 9 do sl:='0'+sl;
      writeln(sl);
      halt;
    end;
    z:=z+f;
    if z >= md then dec(z,md);
  end;
  writeln('2');
  close(input);
  close(output);
end.