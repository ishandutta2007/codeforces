{$R-,S-,Q-,I-,O+}
{$M 34567890}
var
  n,m: int64;
  tt,qq: longint;

function go(i,j:int64):int64;
var                       
  x,y,tmp: int64;
begin
  if (i = 0) or (j = 0) then go:=0 else
  begin
    if i < j then begin tmp:=i; i:=j; j:=tmp; end;
    if go(i mod j,j) = 0 then x:=1 else
    begin
      y:=i div j;
      if (y mod (j+1)) mod 2 = 0 then x:=1
      else x:=0;
    end;
    go:=x;
  end;
end;

begin
  read(tt);
  for qq:=1 to tt do
  begin
    read(n,m);
    if go(n,m) = 1 then writeln('First')
    else writeln('Second');
  end;
end.