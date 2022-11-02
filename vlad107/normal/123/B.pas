{$r-,q-,s-,i-,o+}
var
  c1,c2,r1,r2,a,b,x1,y1,x2,y2:int64;
  function right(a,b:int64):int64;
    var
      ll,rr,mid:int64;
    begin
      ll:=-2000000000;rr:=2000000000;
      while (ll<rr-1)do begin
        mid:=(ll+rr)div 2;
        if (mid*b<=a)then ll:=mid else rr:=mid;
      end;
      if (b*ll>a)then right:=ll else right:=rr;
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(a,b,x1,y1,x2,y2);
  c1:=right(x1+y1,2*a);
  c2:=right(x2+y2,2*a);
  r1:=abs(c1-c2);
  c1:=right(x1-y1,2*b);
  c2:=right(x2-y2,2*b);
  r2:=abs(c1-c2);
  if (r1<r2)then writeln(r2)else writeln(r1);
  close(output);close(input);
end.