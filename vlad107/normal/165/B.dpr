{$r-,q-,s-,i-,o+}
var
  n,k,ll,rr:longint;

  function ok(x:longint):boolean;
    var
      t,i,res:longint;
      
    begin
      t:=x;
      res:=0;
      for i:=1 to 100 do begin
        if (t=0)then break;
        inc(res,t);
        t:=t div k;
      end;
      ok:=res>=n;
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,k);
  ll:=1;rr:=n;
  while (ll<rr-1)do 
    if (ok((ll+rr)shr 1))
      then rr:=(ll+rr)shr 1
      else ll:=(ll+rr)shr 1;
  if (ok(ll))
    then writeln(ll)
    else writeln(rr);
  close(output);close(input);
end.