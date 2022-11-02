{$r-,q-,s-,i-,o+}
var
  j,a,b,k,i,ll,rr:longint;
  p:array[0..1111111]of longint;

  function ok(l:longint):boolean;
    begin
      for i:=a to b-l+1 do 
        if (p[i+l-1]-p[i-1]<k)then begin
          ok:=false;
          exit;
        end;
      ok:=true;
    end;

begin
  read(a,b,k);
  for i:=2 to b do p[i]:=1;
  for i:=1 to b do begin
    if (p[i]=1)then for j:=2 to b div i do p[i*j]:=0;
    inc(p[i],p[i-1]);
  end;
  ll:=1;rr:=b-a+1;
  while (ll<rr-1)do if (ok((ll+rr)shr 1))then rr:=(ll+rr)shr 1 else ll:=(ll+rr) shr 1;
  if (ok(ll))then writeln(ll)else
  if (ok(rr))then writeln(rr)else
  writeln(-1);
end.