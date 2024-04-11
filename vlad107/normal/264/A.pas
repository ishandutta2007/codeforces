{$r-,q-,s-,i-,o+}
var
  a,nom:array[0..1010000]of longint;
  s:ansistring;
  n,t,i:longint;

begin
  readln(s);
  n:=length(s);
  t:=0;
  for i:=1 to length(s)do begin
    if (s[i]='r')then begin
      nom[i]:=t+1;
      inc(t);
    end else nom[i]:=t+1+n-i;
  end;
  for i:=1 to n do a[nom[i]]:=i;
  for i:=1 to n do writeln(a[i]);
end.