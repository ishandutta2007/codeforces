const
  base=1000000007;

var
  res,n,m,i,j:longint;
  kol:array[0..500500]of longint;
  used:array[0..50500,'a'..'z']of boolean;
  s:ansistring;

begin
  readln(n,m);
  fillchar(used,sizeof(used),false);
  fillchar(kol,sizeof(kol),$0);
  for i:=1 to n do begin
    readln(s);
    for j:=1 to length(s)do 
      if (not used[j][s[j]])then begin
        used[j][s[j]]:=true;
        inc(kol[j]);
      end;
  end;
  res:=1;
  for i:=1 to m do res:=int64(res)*kol[i] mod base;
  writeln(res);
end.