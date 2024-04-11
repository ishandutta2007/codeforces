{$r-,q-,s-,i-,o+}
var
  max,x,i,n:longint;
  a,f:array[0..500500]of longint;

  procedure check(x:longint);
    var
      i:longint;
      
    begin
      if (n div x<3)then exit;
      for i:=1 to x do f[i]:=a[i];
      for i:=x+1 to n do begin
        f[i]:=f[i-x]+a[i];
        if (i+x>n)and(f[i]>max)then max:=f[i];
      end;
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  x:=1;
  max:=-maxlongint;
  while (x*x<=n)do begin
    if (n mod x=0)then begin
      check(n div x);
      check(x);
    end;
    inc(x);
  end;
  writeln(max);
  //close(output);close(input);
end.