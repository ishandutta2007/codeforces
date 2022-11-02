{$r-,q-,s-,i-,o+}
var
  n,k,i,j,tmp:longint;
  a:array[0..500500]of longint;

begin
//  assign(input,'input.txt');reset(Input);
//  assign(output,'output.txt');rewrite(output);
  read(n,k);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do 
    for j:=1 to n-1 do 
      if (a[j]<a[j+1])then begin
        tmp:=a[j];a[j]:=a[j+1];a[j+1]:=tmp;
      end;
  j:=0;
  for i:=1 to n do
    if (a[i]>0)and(a[i]>=a[k])then inc(j);
  writeln(j);
//  close(output);close(input);
end.