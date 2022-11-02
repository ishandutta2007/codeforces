const
  abc:array[1..11]of string=('ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA', 'VODKA', 'WHISKEY', 'WINE');
var                         
  j,n,i,res:longint;
  s:string;
begin
  readln(n);
  res:=0;
  for i:=1 to n do begin
    readln(s);
    if (s[1]in['0'..'9'])then begin
      val(s,j);
      if (j<18)then inc(res);
    end else begin
      j:=1;
      while (j<=11)and(s<>abc[j])do inc(j);
      if (j<=11)then inc(res);
    end;
  end;
  writeln(res);
end.