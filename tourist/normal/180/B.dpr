{$R-,S-,Q-,I-,O+}
var
  typ,aux: array [0..1111] of longint;
  b,dd,d,x,i: longint;

function gcd(a,b:longint):longint;
begin
  while (a > 0) and (b > 0) do
    if a > b then a:=a mod b
    else b:=b mod a;
  gcd:=a+b;
end;

begin
  read(b,dd);
  for d:=2 to dd do
  begin
    typ[d]:=0;
    x:=1;
    for i:=1 to 1000 do
    begin
      x:=x*b mod d;
      if x = 0 then
      begin
        typ[d]:=2;
        aux[d]:=i;
        break;
      end;
    end;
    if typ[d] = 0 then
      if b mod d = 1 then typ[d]:=3 else
      if b mod d = d-1 then typ[d]:=11 else
      begin
        for i:=2 to d-1 do
          if d mod i = 0 then
            if gcd(i,d div i) = 1 then
              if (typ[i] <> 7) and (typ[d div i] <> 7) then
              begin
                typ[d]:=6;
                break;
              end;
        if typ[d] = 0 then typ[d]:=7;
      end;
  end;
  writeln(typ[dd],'-type');
  if typ[dd] = 2 then writeln(aux[dd]);
end.