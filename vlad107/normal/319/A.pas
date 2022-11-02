{$r-,q-,s-,i-,o+}
const
  base=1000000007;

var
  a1,a2,cr,ls,x,i,ans:longint;
  s:ansistring;

begin
  readln(s);
  ls:=length(s);
  cr:=0;
  for x:=1 to ls do 
    if (s[x]='1')then begin
      a1:=1;a2:=1;
      for i:=1 to x-1 do a1:=(a1+a1)mod base;
      for i:=1 to ls-x do a2:=(a2+a2)mod base;
      a2:=int64(a2)*a2 mod base;
      a2:=int64(a2)*a1 mod base;
      cr:=(cr+a2)mod base;
    end;
  writeln(cr);
end.