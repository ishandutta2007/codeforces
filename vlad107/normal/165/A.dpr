{$r-,q-,s-,i-,o+}
var
  res,n,i,j:longint;
  x,y:array[0..500500]of longint;
  f1,f2,f3,f4:boolean;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do read(x[i],y[i]);
  res:=0;
  for i:=1 to n do begin 
    f1:=false;f2:=false;f3:=false;f4:=false;
    for j:=1 to n do begin
      if (x[j]=x[i])and(y[j]<y[i])then f1:=true;
      if (x[j]=x[i])and(y[j]>y[i])then f2:=true;
      if (y[j]=y[i])and(x[j]<x[i])then f3:=true;
      if (y[j]=y[i])and(x[j]>x[i])then f4:=true;
    end;
    inc(res,ord(f1 and f2 and f3 and f4));
  end;
  writeln(res);
  close(output);close(input);
end.