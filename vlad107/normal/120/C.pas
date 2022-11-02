uses
  math;
var
  x,res,sum,n,k,i:longint;

begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  read(n,k);
  sum:=0;res:=0;
  for i:=1 to n do begin
    read(x);
    sum:=sum+x;
    res:=res+min(x div k,3)*k;
  end;
  writeln(sum-res);
  close(output);close(input);
end.