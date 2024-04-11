var
  a:array[0..500500]of longint;
  k,i,n:longint;

begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  read(n,k);
  for i:=1 to n do read(a[i]);
  while (a[k]=0)do begin
    inc(k);
    if (k>n)then k:=1;
  end;
  writeln(k);
  close(output);close(input);
end.