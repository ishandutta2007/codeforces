{$r-,q-,s-,i-,o+}
const
  MAXN=33;
  inf=1000000000;

var
  s:ansistring;
  len:array[0..MAXN]of longint;
  a:array[0..MAXN,0..MAXN]of longint;
  b,c,bc:array[0..MAXN,0..MAXN,0..MAXN]of longint;
  eq:array[0..MAXN,0..MAXN,0..MAXN,0..MAXN,0..MAXN]of boolean;
  f,was:array[0..MAXN,0..MAXN,0..MAXN]of boolean;
  g0,g1:array[0..MAXN,0..MAXN,0..MAXN]of longint;
  sum,max,cr1,cr2,t,n,i,j,u1,u2:longint;
  ans:boolean;
  
  procedure rec(x,l,d:longint);
    var
      cr1,cr2,ccr1,ccr2,num,i,j:longint;
      ans,cans:boolean;
      
    begin
      if (was[x][l][d])then exit;
      was[x][l][d]:=true;
      num:=0;
      for i:=1 to n do 
        for j:=1 to len[i] do 
          if (eq[i][x][j][l][d])then begin
            inc(num);
            break;
          end;
      num:=num+bc[x][l][d];
      
      ans:=false;
      cr1:=-inf;
      cr2:=inf;
      for i:=1 to n do 
        for j:=1 to len[i] do 
          if (eq[i][x][j][l][d])then begin
            if (j>1)then begin
              rec(i,j-1,d+1);
              cans:=f[i][j-1][d+1];
              ccr1:=g0[i][j-1][d+1];
              ccr2:=g1[i][j-1][d+1];
              if (not ans)and(not cans)then begin
                ans:=true;
                cr1:=ccr2;
                cr2:=ccr1;
              end else 
              if (not cans=ans)then begin
                if (ccr2>cr1)or(ccr2=cr1)and(ccr1<cr2)then begin
                  cr1:=ccr2;
                  cr2:=ccr1;
                end;
              end;
            end;
            if (j+d<=len[i])then begin
              rec(i,j,d+1);
              cans:=f[i][j][d+1];
              ccr1:=g0[i][j][d+1];
              ccr2:=g1[i][j][d+1];
              if (not ans)and(not cans)then begin
                ans:=true;
                cr1:=ccr2;
                cr2:=ccr1;
              end else 
              if (not cans=ans)then begin
                if (ccr2>cr1)or(ccr2=cr1)and(ccr1<cr2)then begin
                  cr1:=ccr2;
                  cr2:=ccr1;
                end;
              end;
            end;
          end;
      if (cr2=inf)then begin
        ans:=false;
        cr1:=0;
        cr2:=num; 
      end else inc(cr2,num);
      f[x][l][d]:=ans;
      g0[x][l][d]:=cr1;
      g1[x][l][d]:=cr2;
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  readln(n);
  for i:=1 to n do begin
    readln(s);
    len[i]:=length(s);
    for j:=1 to len[i] do a[i][j]:=ord(s[j])-96;
    for u1:=1 to len[i] do begin
      max:=-inf;
      sum:=0;
      for u2:=u1 to len[i] do begin
        if (a[i][u2]>max)then max:=a[i][u2];
        inc(sum,a[i][u2]);
        c[i][u1][u2-u1+1]:=max;
        b[i][u1][u2-u1+1]:=sum;
        bc[i][u1][u2-u1+1]:=b[i][u1][u2-u1+1]*c[i][u1][u2-u1+1];
      end;
    end;
  end;
  
  fillchar(eq,sizeof(eq),false);
  for i:=1 to n do 
    for j:=1 to n do 
      for u1:=1 to len[i] do 
        for u2:=1 to len[j] do 
          for t:=1 to len[i] do begin
            if (u1+t-1>len[i])then break;
            if (u2+t-1>len[j])then break;
            if (a[i][u1+t-1]<>a[j][u2+t-1])then break;
            eq[i][j][u1][u2][t]:=true;
          end;
  
  fillchar(was,sizeof(was),false);  
  ans:=false;
  cr1:=-inf;
  cr2:=inf;
  for i:=1 to n do 
    for u1:=1 to len[i] do begin
      rec(i,u1,1);
	  if (ans)and(f[i][u1][1])then continue;
	  if (not ans)and(not f[i][u1][1])then begin
	    ans:=true;
	    cr1:=g1[i][u1][1];
	    cr2:=g0[i][u1][1];
	    continue;
	  end;
	  if (g1[i][u1][1]>cr1)or(g1[i][u1][1]=cr1)and(g0[i][u1][1]<cr2)then begin
	    cr1:=g1[i][u1][1];
		cr2:=g0[i][u1][1];
	  end;
    end;
  if (ans)then writeln('First')else writeln('Second');
  writeln(cr1,' ',cr2);
  close(output);close(input);
end.