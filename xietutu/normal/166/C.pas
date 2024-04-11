var a:array[0..500]of longint;
    n,p,i,position,min,pp:longint;
procedure kp(l,r:longint);
var i,j,mid,t:longint;
begin
   i:=l;j:=r; mid:=a[(l+r) shr 1];
   repeat
     while a[i]<mid do inc(i);
     while a[j]>mid do dec(j);
     if i<=j then
       begin
         t:=a[i]; a[i]:=a[j]; a[j]:=t;
         inc(i); dec(j);
       end;
   until i>j;
   if i<r then kp(i,r);
   if j>l then kp(l,j);
end;

begin
read(n,p);
    for i:=1 to n do read(a[i]);
    kp(1,n);
    position:=-1;
    min:=maxlongint;
    for i:=1 to n do
      if a[i]=p then
        begin
          position:=i;
          if position=(n+1) div 2 then
           begin
            writeln(0);
            close(input); close(output);
            halt;
           end;
          if position>(n+1) div 2  then
            begin
              if position-(n-position)-1<min then min:=position-(n-position)-1;
            end else
              if n-position-position<min then min:=n-position-position;
        end;
    if position<>-1 then
       begin
        if min<0 then write(0) else writeln(min);
        close(input); close(output);
        halt;
      end;
     pp:=-1;
     for i:=1 to n do
      if a[i]>p then
       begin
         pp:=i-1;
         break;
       end;
     if pp=-1 then
       writeln(n+1)
     else
     if pp>=(n+1) div 2 then
       writeln(pp-n+pp+1)
     else
       writeln(n-pp-pp);
end.