{$r-,q-,s-,i-,o+}
var
  res,t1,t2,n,i,j:longint;
  s:ansistring;
  c1,c2:char;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  readln(s);
  s:=s+'!';
  readln(n);
  for i:=1 to n do begin
    readln(c1,c2);
    t1:=0;t2:=0;
    for j:=1 to length(s)do 
      if (s[j]=c1)then inc(t1)else
      if (s[j]=c2)then inc(t2)else begin
        if (t1<t2)then inc(res,t1)else inc(res,t2);
        t1:=0;t2:=0;
      end;
  end;
  writeln(res);
  close(output);close(Input);
end.