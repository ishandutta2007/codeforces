{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,m,a,b,i,x: longint;
  cc,ch: char;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  a:=1; b:=n;
  for i:=1 to m do
  begin
    read(ch);
    while not (ch in ['l','r']) do read(ch);
    cc:=ch;
    while ch <> 'o' do read(ch);
    read(ch,x);
    if cc = 'l' then
    begin
      if x-1 < b then b:=x-1;
    end else
      if x+1 > a then a:=x+1;
  end;
  if a > b then writeln(-1)
  else writeln(b-a+1);
  close(input);
  close(output);
end.