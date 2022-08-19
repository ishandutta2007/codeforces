{$R-,S-,Q-,I-,O+}
var
  sa,sb: array [0..1000010] of longint;
  a,b: ansistring;
  d,res,n,m,k,i,j,q: longint;
begin
  readln(n);
  readln(a);
  readln(b);
  m:=length(a);
  k:=length(b);
  i:=1; j:=1;
  sa[0]:=0; sb[0]:=0;
  for q:=1 to m*k do
  begin
    if a[i] = b[j] then d:=0 else
    if (a[i] = 'R') and (b[j] = 'S') or
       (a[i] = 'S') and (b[j] = 'P') or
       (a[i] = 'P') and (b[j] = 'R') then d:=1
    else d:=2;
    sa[q]:=sa[q-1]+(d and 1);
    sb[q]:=sb[q-1]+(d and 2) shr 1;
    inc(i); inc(j);
    if i > m then i:=1;
    if j > k then j:=1;
  end;
  res:=sb[m*k]*(n div (m*k))+sb[n mod (m*k)];
  write(res,' ');
  res:=sa[m*k]*(n div (m*k))+sa[n mod (m*k)];
  writeln(res);
end.