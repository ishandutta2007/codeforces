{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  n,i,k: longint;
  p: array [0..1000010] of longint;
  s: array [0..1000010] of char;
  was: array [0..1000010] of boolean;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  n:=0;
  while True do
  begin
    inc(n);
    read(s[n]);
    if not (s[n] in ['a'..'z']) then
    begin
      dec(n);
      break;
    end;
  end;
  p[1]:=0; k:=0;
  for i:=2 to n do
  begin
    while (k > 0) and (s[i] <> s[k+1]) do k:=p[k];
    if s[i] = s[k+1] then inc(k);
    p[i]:=k;
  end;
  fillchar(was,sizeof(was),False);
  for i:=1 to n-1 do was[p[i]]:=True;
  while p[n] > 0 do
  begin
    if was[p[n]] then break;
    p[n]:=p[p[n]];
  end;
  if p[n] = 0 then writeln('Just a legend') else
  begin
    for i:=1 to p[n] do write(s[i]);
    writeln;
  end;
  close(input);
  close(output);
end.