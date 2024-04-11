import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

/*
br = new BufferedReader(new FileReader("input.txt"));
pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
br = new BufferedReader(new InputStreamReader(System.in));
pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		String str = br.readLine();
		for(int qq = 0; qq < 255; qq++)	{
			str = str.replaceAll("  ", " ");
		}
		ArrayList<String> token = new ArrayList<String>();
		for(int i = 0; i < str.length();)	{
			if(str.charAt(i) == ' ' || str.charAt(i) == ',')	{
				token.add(String.valueOf(str.charAt(i)));
				i++;
			}
			else if(i + 2 < str.length() && str.substring(i, i+3).equals("..."))	{
				token.add("...");
				i += 3;
			}
			else	{
				int j = i+1;
				while(j < str.length() && Character.isDigit(str.charAt(j)))
					j++;
				token.add(str.substring(i,j));
				i=j;
			}
		}
		StringBuilder sb = new StringBuilder();
		for(String out: token)	{
			if(out.equals(" "))	{
				if(sb.length() != 0 && sb.charAt(sb.length()-1) != ' ')	{
					sb.append(out);
				}
			}
			else if(out.equals(","))	{
				sb.append(out + " ");
			}
			else if(out.equals("..."))	{
				if(sb.length() == 0 || sb.charAt(sb.length()-1) != ' ')	{
					sb.append(" ");
				}
				sb.append(out);
			}
			else	{
				sb.append(out);
			}
		}
		String ret = sb.toString().trim();
		ret = ret.replaceAll("0 ,", "0,");
		ret = ret.replaceAll("1 ,", "1,");
		ret = ret.replaceAll("2 ,", "2,");
		ret = ret.replaceAll("3 ,", "3,");
		ret = ret.replaceAll("4 ,", "4,");
		ret = ret.replaceAll("5 ,", "5,");
		ret = ret.replaceAll("6 ,", "6,");
		ret = ret.replaceAll("7 ,", "7,");
		ret = ret.replaceAll("8 ,", "8,");
		ret = ret.replaceAll("9 ,", "9,");
		for(int i = 0; i < 10; i++)	{
			ret = replace(ret, (char)(i+'0'));
		}
		ret = replace(ret, ',');
		pw.println(ret);
		pw.close();
	}

	public static String replace(String ret, char dig)	{
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < ret.length();)	{
			if(i+2 < ret.length() && ret.substring(i, i+3).equals(". " + dig))	{
				sb.append("." + dig);
				i += 3;
			}
			else	{
				sb.append(ret.charAt(i++));
			}
		}
		return sb.toString();
	}
	
	/* NOTEBOOK CODE */

	private static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	private static String nextToken() throws IOException	{
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}