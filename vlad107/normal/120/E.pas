var
  n,tt:longint;

begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  read(tt);
  while (tt>0)do begin
    dec(tt);
    read(n);
    writeln(1-(n mod 2))
  end;
end.