{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const p: array [1..12] of string = ('January','February','March','April','May','June','July','August','September','October','November','December');
var
  k,i,x: longint;
  s: string;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(s);
  read(k);
  x:=0;
  for i:=1 to 12 do
    if p[i] = s then x:=i;
  for i:=1 to k do
    if x = 12 then x:=1
    else inc(x);
  writeln(p[x]);
  close(input);
  close(output);
end.