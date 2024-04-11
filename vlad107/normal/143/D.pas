var
  n,m:int64;

begin
  read(n,m);
  if (n=1)or(m=1)then begin
    writeln(n+m-1);
    exit;
  end;
  if (n=2)or(m=2)then begin
    n:=(n+m-2);
    if ((n-1)mod 4=0)then writeln(n+1) else writeln(n+((4-(n mod 4))mod 4));
    exit;
  end;
  writeln((n*m+1) div 2);
end.