{$r-,q-,s-,i-,o+}
var
  y,x,n,i:longint;
  a:array[0..500500]of longint;
  procedure qs(l,r:longint);
    var
      i,j,x,tmp:longint;
    begin
      i:=l;j:=r;
      x:=a[l+random(r-l+1)];
      while (i<=j)do begin
        while (x>a[i])do inc(i);
        while (x<a[j])do dec(j);
        if (i>j)then break;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  randomize;
  read(n);
  for i:=1 to n do read(a[i]);
  qs(1,n);
  for i:=1 to n-1 do begin  
    if (a[i]=a[i+1])then continue;
    if (a[i]<=10)and(a[i+1]<=10)then begin
      x:=(1 shl a[i])-1;
      x:=x*x;
      y:=(1 shl a[i+1])-1;
      if (x>y)then begin
        writeln('YES');
        exit;
      end;
    end else if (a[i+1]<a[i]+a[i])then begin
               writeln('YES');
               exit;
             end;
  end;
  writeln('NO');             
end.