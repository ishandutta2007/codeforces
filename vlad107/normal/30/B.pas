const
  cm:array[1..12]of longint=(31,28,31,30,31,30,31,31,30,31,30,31);
var
  s:string;
  i,dd,mm,yy,bd,bm,by:longint;
  km:array[1..12]of longint;
  function solve(bd,bm,by:longint):boolean;
    begin
      solve:=false;
      if (bm>12)or(bm<1)then exit;
      if (bd>km[bm]+ord((bm=2)and(by mod 4=0)))or(bd<1)then exit;
      if (yy-by<>18)
        then begin
          solve:=yy-by>18;
          exit;
        end;
      if (bm<mm)or(bm=mm)and(bd<=dd)
        then solve:=true
        else solve:=false;
    end;
begin
  for i:=1 to 12 do km[i]:=cm[i];
  readln(s);
  dd:=ord(s[1])-48;
  dd:=dd*10+ord(s[2])-48;
  mm:=ord(s[4])-48;
  mm:=mm*10+ord(s[5])-48;
  yy:=ord(s[7])-48;
  yy:=yy*10+ord(s[8])-48;
  readln(s);
  bd:=ord(s[1])-48;
  bd:=bd*10+ord(s[2])-48;
  bm:=ord(s[4])-48;
  bm:=bm*10+ord(s[5])-48;
  by:=ord(s[7])-48;
  by:=by*10+ord(s[8])-48;
  if (solve(bd,bm,by))or(solve(bd,by,bm))or(solve(bm,bd,by))or
     (solve(bm,by,bd))or(solve(by,bd,bm))or(solve(by,bm,bd))
       then writeln('YES')else writeln('NO');
end.