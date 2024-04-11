{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const co = 2000000;
var
  ans,n,x,i,c: longint;
  ok: boolean;
  a: array [0..100010] of longint;
  b,u: array [0..co+10] of boolean;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,x);
  for i:=1 to n do read(a[i]);
  if x = 2 then
  begin
    writeln(0);
    halt;
  end;
  for i:=1 to n do
    if a[i] = 1 then
    begin
      writeln(1);
      halt;
    end;
  ok:=False;
  for i:=1 to n do
    if a[i] = 2 then
    begin
      ok:=True;
      break;
    end;
  if not ok then
  begin
    writeln(-1);
    halt;
  end;
  if x = 3 then
  begin
    writeln(1);
    halt;
  end;
  if x and 1 = 1 then dec(x);
  fillchar(b,sizeof(b),True);
  b[1]:=False;
  for i:=2 to co do
    if b[i] then
    begin
      c:=i*i;
      if c > co then break;
      while c <= co do
      begin
        b[c]:=False;
        inc(c,i);
      end;
    end;
  fillchar(u,sizeof(u),False);
  for i:=1 to n do
    if a[i] <= co then u[a[i]]:=True;
  ans:=0;
  for i:=2 to co do
    if i > x then break else
    if b[i] and not u[i] then
    begin
      writeln(-1);
      halt;
    end else
    if b[i] then inc(ans);
  writeln(ans);
  close(input);
  close(output);
end.