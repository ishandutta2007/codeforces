{$r-,q-,s-,i-,o+}
var
  res:int64;
  i,j,maxac,maxbd,cr,n,m,s:longint;

begin
  read(n,m,s);
  res:=0;
  for maxac:=1 to n do 
    if (maxac and 1=1)then 
      for maxbd:=1 to m do 
        if (maxbd and 1=1)then 
          if (maxac*maxbd=s)then begin
            cr:=((maxac+1)div 2)*((maxbd+1)div 2)*2-1;
            res:=res+int64(cr)*(n-maxac+1)*(m-maxbd+1);
          end else 
          if (maxac*maxbd>s)then 
            for i:=1 to maxac-1 do 
              if (i and 1=1)then begin
                //s=i*maxbd+j*maxac
                if ((s-i*maxbd)mod (maxac-i)<>0)then continue;
                j:=(s-i*maxbd)div (maxac-i);
                if (j<=0)then continue;
                if (j and 1<>1)then continue;
                if (j>=maxbd)then continue;
                res:=res+int64(n-maxac+1)*(m-maxbd+1)*2;
              end;
  writeln(res);
end.