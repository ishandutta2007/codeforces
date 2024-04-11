{$r-,q-,s-,i-,o+}
var
  nom,n,k,x,q:int64;
  tt:longint;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n,k,tt);
  k:=n-k;
  q:=n div 2;
  while (tt>0)do begin
    dec(tt);
    read(x);
    if (x=n)then begin
      if (k=n)then write('.') else write('X');
      continue;
    end;
    if (x mod 2=1)then nom:=(x+1)div 2 else nom:=q+(x div 2);
    if (nom<=k)then write('.')else write('X');
  end;
  writeln;
  close(output);close(input);
end.