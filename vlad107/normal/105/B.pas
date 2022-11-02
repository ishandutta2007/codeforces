{$r-,q-,s-,i-,o+}
var
  pp,cr,res:extended;
  a,b,t,p:array[0..500]of longint;
  km,kb,mask,tm,i,n,k,ka:longint;
  procedure rec(x,k:longint);
    var
      i:longint;
    begin
      if (x=n)then begin
        t[x]:=10*k;
        for i:=1 to n do begin
          p[i]:=b[i]+t[i];
          if (p[i]>100)then p[i]:=100;
        end;
        cr:=0;
        for mask:=0 to (1 shl n)-1 do begin
          tm:=mask;
          km:=0;
          while (tm>0)do begin
            inc(km);
            tm:=tm and (tm-1);
          end;
          pp:=1;
          tm:=mask;
          for i:=1 to n do begin
            if (tm and 1=1)then pp:=pp*p[i]/100 else pp:=pp*(100-p[i])/100;
            tm:=tm shr 1;
          end;
          if (km>n div 2)then begin
            cr:=cr+pp;
            continue;
          end;
          kb:=0;
          tm:=mask;
          for i:=1 to n do begin
            if (tm and 1=0)then kb:=kb+a[i];
            tm:=tm shr 1;
          end;
          cr:=cr+pp*ka/(ka+kb);          
        end;
        if (cr>res)then res:=cr;
        exit;
      end;
      for i:=0 to k do begin
        t[x]:=10*i;
        rec(x+1,k-i);
      end;
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,k,ka);
  for i:=1 to n do read(a[i],b[i]);
  res:=0;
  rec(1,k);
  writeln(res:0:10);
  close(output);close(input);
end.