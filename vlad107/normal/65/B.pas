var
  a:array[0..100500]of longint;
  cr,j,x,i,n:longint;
  tmp,ch:char;
  s:string;

begin
  read(n); 
  a[0]:=999;
  for i:=1 to n do begin
    read(x);
    str(x,s);
    cr:=2012;
    for j:=1 to 4 do  
      for ch:='0'to'9'do begin
        tmp:=s[j];
        s[j]:=ch;
        val(s,x);
        if (x>=1000)and(x<=2011)and(x<cr)and(x>=a[i-1])then cr:=x;
        s[j]:=tmp;
      end;
    if (cr>=1000)and(cr<=2011)
      then a[i]:=cr
      else begin
        writeln('No solution');
        exit;
      end;
  end;
  for i:=1 to n do writeln(a[i]);
end.