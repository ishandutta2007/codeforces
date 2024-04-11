{$r-,q-,s-,i-,o+}
const
  eps=1e-9;

var
  res:extended;
  t,h,r,p:array[0..500500]of extended;
  i,j,n:longint;
  
  function max(x,y:extended):extended;
    begin
      if (x>y)then max:=x else max:=y;
    end;
    
  function solve(h1,r1,p1,h2,r2,p2:extended):extended;
    var
      ll,l,res:extended;
    begin
      if (r2+eps>=p1)then begin solve:=h1;exit; end;
      res:=0;
      l:=(p2-r1)*h1/(p1-r1)-h2;
      if (l>=-eps)and(l+h2<=h1+eps)then res:=max(res,l);
      l:=(r2-r1)*h1/(p1-r1);
      if (l>=-eps)and(l<=h1+eps)then res:=max(res,l);
      l:=h1-h2*(p1-r2)/(p2-r2);
      ll:=h2*(p1-r2)/(p2-r2);
      if (ll>=-eps)and(ll<=h2+eps)and(l>=-eps)and(l<=h1+eps)then res:=max(res,l);
      solve:=res;
    end;

begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do read(h[i],r[i],p[i]);
  res:=0;
  for i:=1 to n do begin
    t[i]:=0;
    for j:=1 to i-1 do 
      t[i]:=max(t[i],t[j]+solve(h[j],r[j],p[j],h[i],r[i],p[i]));
    res:=max(res,t[i]+h[i]);
  end;
  writeln(res:0:10);
  close(output);close(input);
end.