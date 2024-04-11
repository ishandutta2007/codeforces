{$R+,S+,Q+,I+,O-}
var
  carrots,flour,e,choco: longint;
  bowl: array [0..5] of longint;
begin
  read(carrots);
  e:=1; bowl[1]:=0;
  flour:=1;
  while carrots > 0 do
  begin
    read(choco);
    inc(e); bowl[e]:=choco;
    bowl[e]:=bowl[e]*flour;
    choco:=bowl[e]; dec(e);
    inc(bowl[e],choco);
    inc(e); bowl[e]:=flour;
    inc(bowl[e]);
    flour:=bowl[e]; dec(e);
    dec(carrots);
  end;
  writeln(bowl[1]);
end.