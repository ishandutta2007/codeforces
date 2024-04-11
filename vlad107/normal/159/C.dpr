{$r-,q-,s-,i-,o+}
const
  MAXN=200500;
  
var
  kg:array[0..30]of longint;
  sum:array[0..30,0..MAXN]of longint;
  x,t,k,n,i,j:longint;
  s:ansistring;
  ch:char;
  
  function findsum(x,y:longint):longint;
    var
      res:longint;
      
    begin
      res:=0;
      while (y>0)do begin
        inc(res,sum[x][y]);
        y:=y and (y-1);
      end;
      findsum:=res;
    end;
    
  procedure modify(x,y,val:longint);
    begin
      while (y<=MAXN)do begin
        inc(sum[x][y],val);
        y:=y or (y-1) + 1;
      end;
    end;
    
  function find(x,y:longint):longint;
    var
      mid,ll,rr:longint;
      
    begin
      ll:=1;rr:=MAXN;
      while (ll<rr-1)do begin
        mid:=(ll+rr)shr 1;
        if (findsum(x,mid)>=y)then rr:=mid else ll:=mid;
      end;
      if (findsum(x,ll)=y)then find:=ll else find:=rr;
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  readln(k);
  readln(s);
  readln(n);
  fillchar(kg,sizeof(kg),$0);
  for i:=1 to k do 
    for j:=1 to length(s) do begin
      t:=ord(s[j])-96;
      inc(kg[t]);
      modify(t,kg[t],+1);
    end;
  
  for i:=1 to n do begin
    readln(x,ch,ch);
    t:=ord(ch)-96;
    modify(t,find(t,x),-1);
  end;
  fillchar(kg,sizeof(kg),$0);
  for i:=1 to k do 
    for j:=1 to length(s)do begin
      t:=ord(s[j])-96;
      inc(kg[t]);
      if (findsum(t,kg[t])-findsum(t,kg[t]-1)>0)
        then write(s[j]);
    end;
  writeln;
  close(output);close(input);
end.