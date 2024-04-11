var
  a,b,c,s:string;
  i,n:longint;
  procedure calc(var a:string);
    var
      i:longint;
      b:string;
    begin
      b:='';
      for i:=1 to length(a)do begin
        if (a[i]in['-','_',';'])then continue;
        b:=b+upcase(a[i]);
      end;
      a:=b;
    end;
begin
  readln(a);calc(a);
  readln(b);calc(b);
  readln(c);calc(c);
  readln(n);
  for i:=1 to n do begin
    readln(s);calc(s);
    if (a+b+c=s)or(a+c+b=s)or
       (b+a+c=s)or(b+c+a=s)or
       (c+a+b=s)or(c+b+a=s)
         then writeln('ACC')
         else writeln('WA');
  end;
end.