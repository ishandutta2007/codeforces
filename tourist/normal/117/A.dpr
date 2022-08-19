{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  tt,m,i,s,f,t: longint;

function next(t,s:longint):longint;
var
  u: longint;
begin
  u:=t mod (2*(m-1));
  if u >= m then
  begin
    u:=2*m-1-u;
    if u >= s then t:=t+(u-s)
    else t:=t+(u-1)+(s-1);
  end else
  begin
    u:=u+1;
    if u <= s then t:=t+(s-u)
    else t:=t+(m-u)+(m-s);
  end;
  next:=t;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(tt,m);
  for i:=1 to tt do
  begin
    read(s,f,t);
    if s = f then writeln(t) else
    begin
      t:=next(t,s);
      t:=next(t,f);
      writeln(t);
    end;
  end;
  close(input);
  close(output);
end.