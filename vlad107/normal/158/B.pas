{$r-,q-,s-,i-,o+}
var
  a:array[0..5]of longint;
  i,n,x,res:longint;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n);
  fillchar(a,sizeof(a),$0);
  for i:=1 to n do begin
    read(x);
    inc(a[x]);
  end;
  
  res:=a[4]+a[3];
  dec(a[1],a[3]);
  if (a[1]<0)then a[1]:=0;
  
  res:=res+a[2] div 2;
  a[2]:=a[2] mod 2;
  if (a[2]<>0)then begin
    inc(res);
    dec(a[1],2);
    if (a[1]<0)then a[1]:=0;
  end;
  res:=res+(a[1] div 4);
  if (a[1] mod 4<>0)then inc(res);
  writeln(res);
  //close(output);close(Input);
end.