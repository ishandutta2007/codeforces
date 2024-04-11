var
  res:int64;
  n,i,x:longint;


begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n);
  res:=0;
  for i:=1 to n do begin
    read(x);
    res:=res+1+int64(x-1)*i;
  end;
  writeln(res);
  close(output);
end.