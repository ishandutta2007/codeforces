{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  ans,x1,y1,x2,y2,x3,y3: longint;

procedure get(var x:longint);
var
  ch: char;
begin
  read(ch);
  while not (ch in ['a'..'h']) do read(ch);
  x:=Ord(ch)-96;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  get(x1); read(y1);
  get(x2); read(y2);
  ans:=0;
  for x3:=1 to 8 do
    for y3:=1 to 8 do
      if (x1 <> x3) and (y1 <> y3) then
        if sqr(x1-x3)+sqr(y1-y3) <> 5 then
          if sqr(x2-x3)+sqr(y2-y3) <> 5 then inc(ans);
  writeln(ans-1);
  close(input);
  close(output);
end.