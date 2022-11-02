var c,v,n,k,cpos,i,j:longint;
    o:array[1..50]of longint;

begin
readln(n,v);
cpos:=1;
for i:=1 to n do
begin
   read(k);
   for j:=1 to k do
   begin
      read(c);
      if c<v then begin o[cpos]:=i;inc(cpos);break;end;
   end;
   readln;
end;
writeln(cpos-1);
for i:=1 to cpos-1 do
   write(o[i],' ');
end.