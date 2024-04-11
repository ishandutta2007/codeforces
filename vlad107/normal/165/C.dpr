{$r-,q-,s-,i-,o+}
var
  res:int64;
  k,i,n,cr:longint;
  f,a:array[0..1111111]of longint;
  s:ansistring;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  readln(k);
  readln(s);
  n:=length(s);
  for i:=1 to n do a[i]:=ord(s[i])-48;
  fillchar(f,sizeof(f),$0);
  res:=0;
  f[0]:=1;
  cr:=0;
  for i:=1 to n do begin
    inc(cr,a[i]);
    if (cr>=k)then res:=res+f[cr-k];
    inc(f[cr]);
  end;
  writeln(res);
  close(output);close(input);
end.